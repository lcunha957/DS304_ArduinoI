// Aula realizada em 18-05-2022 pelos RAs:
// 21101 - Leandro Freitas
// 21106 - Lunara Cunha
// Disciplina: DS303

const express = require('express');
const app = express();
const port = 3000;
const { SerialPort } = require('serialport')
// or
//import { SerialPort } from 'serialport'

// Create a port
const arduinoSerialPort = new SerialPort({
  path: '/dev/cu.usbserial-2110',
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
    return res.send('Working' +   '<a href="botoes"><button>Botões</button></a>');
});

app.get('/botoes', function (req, res) {
  return res.send('<a href="led"><button>Você achou o botão1</button></a>' + 
  '<a href="brilha"><button>Você achou o botão2</button></a>' +
  '<a href="raio"><button>Você achou o botão3</button></a>' +
  '<a href="lua"><button>Você achou o botão4</button></a>' +
  '<a href="Venus"><button>Você achou o botão5</button></a>' +
  '<a href="off"><button>Você achou o botão6</button></a>')
});

app.get('/:action', function (req, res) {
   var action = req.params.action || req.param('action');
    if(action == 'led'){
        arduinoSerialPort.write("w");
        return res.send('All leds are on!' +   '<a href="botoes"><button>Voltar</button></a>');
        
    }
    if(action == 'brilha'){
      arduinoSerialPort.write("b");
      return res.send('Led 1 is on!' + '<a href="botoes"><button>Voltar</button></a>');
  }
  if(action == 'raio'){
    arduinoSerialPort.write("x");
    return res.send('Led 2 is on!' +   '<a href="botoes"><button>Voltar</button></a>');
}
if(action == 'lua'){
  arduinoSerialPort.write("d");
  return res.send('Led 3 is on!' +   '<a href="botoes"><button>Voltar</button></a>');
}
if(action == 'Venus'){
  arduinoSerialPort.write("r");
  return res.send('Leds 1 and 3 are on!' +   '<a href="botoes"><button>Voltar</button></a>');
}
    if(action == 'off') {
        arduinoSerialPort.write("t");
        return res.send('All leds  are off!' +  '<a href="botoes"><button>Voltar</button></a>');
    }
    return res.send('Action: ' + action);
});
app.listen(port, function () {
console.log('Example app listening on port http://0.0.0.0:' + port + '!');
});
