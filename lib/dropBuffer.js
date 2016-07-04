var dropBuffer = require('../build/Release/binding.node');
module.exports = function(obj){
  if(typeof obj == 'object')
  	dropBuffer(obj);
}