#include <stdlib.h>
#include <node.h>
#include <v8.h>
#include <node_buffer.h>

using v8::ArrayBuffer;
using v8::HandleScope;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::Value;
using v8::Uint8Array;

inline bool HasInstance(Local<Object> obj) {
  return obj->IsUint8Array();
}

void Method(const v8::FunctionCallbackInfo<v8::Value>& args) {
  Isolate* isolate = args.GetIsolate();
  HandleScope scope(isolate);
  Local<Object> buf = args[0].As<Object>();
  if(!HasInstance(buf))
    return;
  Local<Uint8Array> array = buf.As<Uint8Array>();
  if (array->Buffer()->GetContents().ByteLength() <= 8 * 1024 
    || array->Buffer()->IsExternal())
    return;
  int64_t change_in_bytes = -static_cast<int64_t>(array->Buffer()->GetContents().ByteLength());
  ArrayBuffer::Contents array_c = array->Buffer()->Externalize();
  free(array_c.Data());
  isolate->AdjustAmountOfExternalAllocatedMemory(change_in_bytes);
}

void init(v8::Local<v8::Object> exports, v8::Local<v8::Object> module) {
  NODE_SET_METHOD(module, "exports", Method);
}

NODE_MODULE(binding, init);