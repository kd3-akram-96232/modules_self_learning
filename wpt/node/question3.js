const http = require('http');

let products = [
    {
        id: 1,
        name: 'Laptop'
    },
    {
        id: 2,
        name: 'Mobile'
    }
];

const server = http.createServer((req, res) => {

    // GET
    if(req.method === 'GET' && req.url === '/products'){

        res.writeHead(200, {
            'Content-Type': 'application/json'
        });

        res.end(JSON.stringify(products));
    }

    // POST
    else if(req.method === 'POST' && req.url === '/products'){

        let body = '';

        req.on('data', chunk => {
            body += chunk.toString();
        });

        req.on('end', () => {

            const newProduct = JSON.parse(body);

            products.push(newProduct);

            res.end('Product Added');
        });
    }

    // PUT
    else if(req.method === 'PUT' && req.url === '/products/1'){

        products[0].name = 'Updated Laptop';

        res.end('Product Updated');
    }

    // DELETE
    else if(req.method === 'DELETE' && req.url === '/products/1'){

        products = products.filter(p => p.id !== 1);

        res.end('Product Deleted');
    }

    else{
        res.end('Route Not Found');
    }

});

server.listen(3000, () => {
    console.log('Server running on port 3000');
});