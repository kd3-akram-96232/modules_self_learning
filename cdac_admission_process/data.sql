INSERT INTO centres (centre_name) VALUES
('ACTS Pune'),
('Sunbeam Pune'),
('Sunbeam Karad'),
('IACSD Pune'),
('Infoway Pune');

INSERT INTO courses (course_name) VALUES
('PGCP-AC'),
('PGCP-BDA');

INSERT INTO centre_courses (centre_id, course_id, total_seats) VALUES
(1, 1, 50), -- ACTS Pune - PGCP-AC
(1, 2, 30), -- ACTS Pune - PGCP-BDA
(2, 1, 40), -- Sunbeam Pune - PGCP-AC
(2, 2, 20), -- Sunbeam Pune - PGCP-BDA
(3, 1, 30), -- Sunbeam Karad - PGCP-AC
(4, 1, 60), -- IACSD Pune - PGCP-AC
(4, 2, 40), -- IACSD Pune - PGCP-BDA
(5, 1, 20), -- Infoway Pune - PGCP-AC
(5, 2, 15); -- Infoway Pune - PGCP-BDA

INSERT INTO ccat_result (student_id, student_rank) VALUES
(1001, 5),
(1002, 10),
(1003, 12),
(1004, 15),
(1005, 16),
(1006, 18),
(1007, 20),
(1008, 22),
(1009, 25),
(1010, 28),
(1011, 30),
(1012, 33),
(1013, 35),
(1014, 40),
(1015, 44),
(1016, 48),
(1017, 50),
(1018, 55),
(1019, 60),
(1020, 65),
(1021, 70),
(1022, 75),
(1023, 80),
(1024, 85),
(1025, 90),
(1026, 95),
(1027, 100),
(1028, 105),
(1029, 110),
(1030, 120);

INSERT INTO preferences (student_id, preference_no, centre_course_id) VALUES

-- Top Rank Students (prefer ACTS Pune first)
(1001,1,1),
(1001,2,2),

(1002,1,1),
(1002,2,3),

(1003,1,1),
(1003,2,4),

(1004,1,2),
(1004,2,3),

(1005,1,3),
(1005,2,1),

-- Good Rank Students (Sunbeam Pune)
(1006,1,3),
(1006,2,4),

(1007,1,3),
(1007,2,5),

(1008,1,4),
(1008,2,6),

(1009,1,4),
(1009,2,5),

(1010,1,3),
(1010,2,2),

-- Mid Rank Students (Sunbeam Karad / IACSD)
(1011,1,5),
(1011,2,6),

(1012,1,5),
(1012,2,7),

(1013,1,6),
(1013,2,7),

(1014,1,6),
(1014,2,8),

(1015,1,5),
(1015,2,3),

-- Lower Mid Rank (IACSD / Infoway)
(1016,1,7),
(1016,2,8),

(1017,1,7),
(1017,2,6),

(1018,1,8),
(1018,2,9),

(1019,1,8),
(1019,2,7),

(1020,1,9),
(1020,2,8),

-- Lower Rank Students
(1021,1,9),
(1021,2,7),

(1022,1,8),
(1022,2,9),

(1023,1,9),
(1023,2,8),

(1024,1,8),
(1024,2,6),

(1025,1,9),
(1025,2,5),

-- Lowest Rank Students
(1026,1,7),
(1026,2,8),

(1027,1,8),
(1027,2,9),

(1028,1,9),
(1028,2,7),

(1029,1,8),
(1029,2,9),

(1030,1,9),
(1030,2,8);