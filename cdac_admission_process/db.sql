DROP DATABASE IF EXISTS cdac_admission_process;
CREATE DATABASE cdac_admission_process;

USE cdac_admission_process;

-- Student rank table
CREATE TABLE ccat_result (
    student_id INT PRIMARY KEY AUTO_INCREMENT,
    student_rank INT NOT NULL
);

-- Centres
CREATE TABLE centres (
    centre_id INT PRIMARY KEY AUTO_INCREMENT,
    centre_name VARCHAR(100) UNIQUE NOT NULL
);

-- Courses
CREATE TABLE courses (
    course_id INT PRIMARY KEY AUTO_INCREMENT,
    course_name VARCHAR(50) UNIQUE NOT NULL
);

-- Centre + Course mapping
CREATE TABLE centre_courses (
    centre_course_id INT PRIMARY KEY AUTO_INCREMENT,
    centre_id INT NOT NULL,
    course_id INT NOT NULL,
    total_seats INT NOT NULL,

    FOREIGN KEY (centre_id)
        REFERENCES centres(centre_id)
        ON DELETE CASCADE
        ON UPDATE CASCADE,

    FOREIGN KEY (course_id)
        REFERENCES courses(course_id)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

-- Student preferences
CREATE TABLE preferences (
    preference_id INT PRIMARY KEY AUTO_INCREMENT,
    student_id INT NOT NULL,
    preference_no INT NOT NULL,
    centre_course_id INT NOT NULL,

    FOREIGN KEY (student_id)
        REFERENCES ccat_result(student_id)
        ON DELETE CASCADE
        ON UPDATE CASCADE,

    FOREIGN KEY (centre_course_id)
        REFERENCES centre_courses(centre_course_id)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

-- Final seat allocation
CREATE TABLE allocation_result (
    allocation_id INT PRIMARY KEY AUTO_INCREMENT,
    student_id INT NOT NULL UNIQUE,
    centre_course_id INT NOT NULL,

    FOREIGN KEY (student_id)
        REFERENCES ccat_result(student_id)
        ON DELETE CASCADE
        ON UPDATE CASCADE,

    FOREIGN KEY (centre_course_id)
        REFERENCES centre_courses(centre_course_id)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);