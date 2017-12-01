const express = require('express');
const app = express();
const axios = require('axios');

app.get('/', (req, res) => res.send('Hello World!'));

const onLedIp = 'htpp://192.168.0.109/?led=turnnnnnnnon';
const offLedIp = 'htpp://192.168.0.109/?led=turnnnnnnnoff';
let indicator = 'off';

setInterval(() => {
    if (indicator === 'on') {
        axios.get(offLedIp)
          .then(() => {
              indicator = 'off';
              console.log('the led is going too be ..... turned off! 😃');
          })
          .catch(e => {
            console.log(e);
          });
    } else {
        axios.get(onLedIp)
          .then(() => {
              indicator = 'on';
              console.log('the led is going too be ...... turned on! 😃');
          })
          .catch(e => {
            console.log(e);
          });
    }
}, 1000);


app.listen(3000, () => console.log('Example app listening on port 3000!'));