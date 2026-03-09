
-- function for checking seat availability for a centre_course and allocating if available

DELIMITER $$

CREATE PROCEDURE AllocateSeats()
BEGIN
    -- Declare variables for cursor and availability check
    DECLARE v_student_id INT;
    DECLARE v_pref_centre_course_id INT;
    DECLARE v_preference_no INT;
    DECLARE v_available_seats INT;
    DECLARE v_done INT DEFAULT FALSE;

    -- Cursor: iterate over all students in ascending rank order
    DECLARE student_cursor CURSOR FOR
        SELECT student_id
        FROM ccat_result
        ORDER BY student_rank;

    -- Handler for when cursor finishes
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET v_done = TRUE;

    -- Optional: Clear any previous allocation results before starting fresh
    TRUNCATE TABLE allocation_result;

    -- Open the cursor
    OPEN student_cursor;

    read_loop: LOOP
        FETCH student_cursor INTO v_student_id;
        IF v_done THEN
            LEAVE read_loop;
        END IF;

        -- For the current student, try preferences in order
        -- We use an inner block so we can declare a second cursor
        BLOCK2: BEGIN
            DECLARE pref_done INT DEFAULT FALSE;
            DECLARE pref_cursor CURSOR FOR
                SELECT centre_course_id, preference_no
                FROM preferences
                WHERE student_id = v_student_id
                ORDER BY preference_no;
            DECLARE CONTINUE HANDLER FOR NOT FOUND SET pref_done = TRUE;

            OPEN pref_cursor;

            pref_loop: LOOP
                FETCH pref_cursor INTO v_pref_centre_course_id, v_preference_no;
                IF pref_done THEN
                    LEAVE pref_loop;
                END IF;

                -- Calculate available seats for this centre‑course
                -- Available = total_seats - already allocated
                SELECT cc.total_seats - COUNT(a.student_id) INTO v_available_seats
                FROM centre_courses cc
                LEFT JOIN allocation_result a ON cc.centre_course_id = a.centre_course_id
                WHERE cc.centre_course_id = v_pref_centre_course_id
                GROUP BY cc.centre_course_id;

                -- If seats are available, allocate and break out of preference loop
                IF v_available_seats > 0 THEN
                    INSERT INTO allocation_result (student_id, centre_course_id)
                    VALUES (v_student_id, v_pref_centre_course_id);
                    LEAVE pref_loop;  -- Student allocated, stop checking further preferences
                END IF;
            END LOOP pref_loop;

            CLOSE pref_cursor;
        END BLOCK2;
    END LOOP read_loop;

    CLOSE student_cursor;
END$$

DELIMITER ;



-- to visualise allocations;

SELECT 
    a.allocation_id,
    cr.student_id,
    cr.student_rank,
    c.centre_name,
    co.course_name
FROM allocation_result a
JOIN ccat_result cr ON a.student_id = cr.student_id
JOIN centre_courses cc ON a.centre_course_id = cc.centre_course_id
JOIN centres c ON cc.centre_id = c.centre_id
JOIN courses co ON cc.course_id = co.course_id
ORDER BY cr.student_rank;


--- output of above query will be like this;
+---------------+------------+--------------+---------------+-------------+
| allocation_id | student_id | student_rank | centre_name   | course_name |
+---------------+------------+--------------+---------------+-------------+
|             1 |       1001 |            5 | ACTS Pune     | PGCP-AC     |
|             2 |       1002 |           10 | ACTS Pune     | PGCP-AC     |
|             3 |       1003 |           12 | ACTS Pune     | PGCP-AC     |
|             4 |       1004 |           15 | ACTS Pune     | PGCP-BDA    |
|             5 |       1005 |           16 | Sunbeam Pune  | PGCP-AC     |
|             6 |       1006 |           18 | Sunbeam Pune  | PGCP-AC     |
|             7 |       1007 |           20 | Sunbeam Pune  | PGCP-AC     |
|             8 |       1008 |           22 | Sunbeam Pune  | PGCP-BDA    |
|             9 |       1009 |           25 | Sunbeam Pune  | PGCP-BDA    |
|            10 |       1010 |           28 | Sunbeam Pune  | PGCP-AC     |
|            11 |       1011 |           30 | Sunbeam Karad | PGCP-AC     |
|            12 |       1012 |           33 | Sunbeam Karad | PGCP-AC     |
|            13 |       1013 |           35 | IACSD Pune    | PGCP-AC     |
|            14 |       1014 |           40 | IACSD Pune    | PGCP-AC     |
|            15 |       1015 |           44 | Sunbeam Karad | PGCP-AC     |
|            16 |       1016 |           48 | IACSD Pune    | PGCP-BDA    |
|            17 |       1017 |           50 | IACSD Pune    | PGCP-BDA    |
|            18 |       1018 |           55 | Infoway Pune  | PGCP-AC     |
|            19 |       1019 |           60 | Infoway Pune  | PGCP-AC     |
|            20 |       1020 |           65 | Infoway Pune  | PGCP-BDA    |
|            21 |       1021 |           70 | Infoway Pune  | PGCP-BDA    |
|            22 |       1022 |           75 | Infoway Pune  | PGCP-AC     |
|            23 |       1023 |           80 | Infoway Pune  | PGCP-BDA    |
|            24 |       1024 |           85 | Infoway Pune  | PGCP-AC     |
|            25 |       1025 |           90 | Infoway Pune  | PGCP-BDA    |
|            26 |       1026 |           95 | IACSD Pune    | PGCP-BDA    |
|            27 |       1027 |          100 | Infoway Pune  | PGCP-AC     |
|            28 |       1028 |          105 | Infoway Pune  | PGCP-BDA    |
|            29 |       1029 |          110 | Infoway Pune  | PGCP-AC     |
|            30 |       1030 |          120 | Infoway Pune  | PGCP-BDA    |
+---------------+------------+--------------+---------------+-------------+
30 rows in set (0.00 sec)
