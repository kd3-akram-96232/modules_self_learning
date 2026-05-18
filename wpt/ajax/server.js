const express = require('express');
const fs = require('fs');

const app = express();

const data = [
    {
        "id": 1,
        "name": "JavaScript Basics",
        "author": "Akram Khan"
    },
    {
        "id": 2,
        "name": "Node.js Guide",
        "author": "John"
    },
    {
        "id": 3,
        "name": "React Master",
        "author": "Alice"
    }
]

app.get('/books', (req, res) => {

        res.json(data);

});

app.listen(3000, () => {
    console.log('Server running on port 3000');
});