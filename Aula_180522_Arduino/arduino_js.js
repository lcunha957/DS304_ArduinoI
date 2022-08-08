const express = require('express');
const app = express();
const port = 3000;
const { SerialPort } = require('serialport')
// or
//import { SerialPort } from 'serialport'

// Create a port
const arduinoSerialPort = new SerialPort({
  path: '/dev/cu.usbserial-210',
  baudRate: 9600,
}, function (err) {
    if (err) {
      return console.log('Error: ', err.message)
    }
});

/*

let SerialPort = require('serialport');

var port = 3000;
var arduinoCOMPort = '/dev/cu.usbserial-210';
/*sp = SerialPort.SerialPort;

const serialport = new SerialPort({ path: '/dev/example', baudRate: 9600 })
serialport.write('ROBOT POWER ON')
*/
//var arduinoSerialPort = new SerialPort.SerialPort(
//    arduinoCOMPort, {path:'/dev/example', baudrate: 9600});
arduinoSerialPort.on('open',function() {
  console.log('Serial Port  is opened.');
});
app.get('/', function (req, res) {
    return res.send('Working');
})
app.get('/:action', function (req, res) {
   var action = req.params.action || req.param('action');
    if(action == 'led'){
        arduinoSerialPort.write("w");
        return res.send('Led light is on!');
    }
    if(action == 'off') {
        arduinoSerialPort.write("t");
        return res.send("Led light is off!");
    }
    return res.send('Action: ' + action);
});
app.listen(port, function () {
console.log('Example app listening on port http://0.0.0.0:' + port + '!');
});