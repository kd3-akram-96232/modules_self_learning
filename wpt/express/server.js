const express = require('express');

const app = express();

app.use(express.json());


// ================= STUDENTS DATA =================

let students = [
    {
        id: 1,
        name: 'Akram',
        course: 'Node JS'
    },
    {
        id: 2,
        name: 'John',
        course: 'React'
    }
];


// ================= COURSES DATA =================

let courses = [
    {
        id: 1,
        name: 'Node JS',
        duration: '3 Months'
    },
    {
        id: 2,
        name: 'React JS',
        duration: '2 Months'
    }
];



// =================================================
// STUDENT CRUD
// =================================================


// GET ALL STUDENTS
app.get('/students', (req, res) => {

    res.json(students);

});


// GET SINGLE STUDENT
app.get('/students/:id', (req, res) => {

    const id = Number(req.params.id);

    const student = students.find(s => s.id === id);

    res.json(student);

});


// ADD STUDENT
app.post('/students', (req, res) => {

    const newStudent = req.body;

    students.push(newStudent);

    res.json({
        message: 'Student Added',
        data: newStudent
    });

});


// UPDATE STUDENT
app.put('/students/:id', (req, res) => {

    const id = Number(req.params.id);

    const index = students.findIndex(s => s.id === id);

    students[index] = req.body;

    res.json({
        message: 'Student Updated'
    });

});


// DELETE STUDENT
app.delete('/students/:id', (req, res) => {

    const id = Number(req.params.id);

    students = students.filter(s => s.id !== id);

    res.json({
        message: 'Student Deleted'
    });

});



// =================================================
// COURSE CRUD
// =================================================


// GET ALL COURSES
app.get('/courses', (req, res) => {

    res.json(courses);

});


// GET SINGLE COURSE
app.get('/courses/:id', (req, res) => {

    const id = Number(req.params.id);

    const course = courses.find(c => c.id === id);

    res.json(course);

});


// ADD COURSE
app.post('/courses', (req, res) => {

    const newCourse = req.body;

    courses.push(newCourse);

    res.json({
        message: 'Course Added',
        data: newCourse
    });

});


// UPDATE COURSE
app.put('/courses/:id', (req, res) => {

    const id = Number(req.params.id);

    const index = courses.findIndex(c => c.id === id);

    courses[index] = req.body;

    res.json({
        message: 'Course Updated'
    });

});


// DELETE COURSE
app.delete('/courses/:id', (req, res) => {

    const id = Number(req.params.id);

    courses = courses.filter(c => c.id !== id);

    res.json({
        message: 'Course Deleted'
    });

});



// =================================================
// SERVER
// =================================================

app.listen(3000, () => {

    console.log('Server running on port 3000');

});