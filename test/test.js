var dropBuffer = require('../index.js');

var buf1 = new Buffer('hello');
var buf2 = new Buffer(4095);
var buf3 = new Buffer(4097);

console.log(buf1.toString('utf8'))
dropBuffer(buf2);

setInterval(function(){
   dropBuffer(buf2);
   dropBuffer(buf3);
   buf2 = new Buffer(4090);
   buf3 = new Buffer(102400);
  console.log(buf1.toString('utf8'))
}, 1000)