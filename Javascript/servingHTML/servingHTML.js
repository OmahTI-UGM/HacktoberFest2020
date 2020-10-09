let fs = require('fs');
let http = require('http');

let server = http.createServer((req, res) => {
    res.writeHead(200, { 'Content-Type': 'text/html' });

    let myReadStream = fs.createReadStream(__dirname + '/index.html', 'utf-8');
    myReadStream.pipe(res);
});

server.listen(3000, '127.0.0.1');
console.log('Listening to port 3000');