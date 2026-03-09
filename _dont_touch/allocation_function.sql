DELIMITER $$
CREATE FUNCTION CENTER_COURSE_IS_AVAILABLE(centre_course_id int)
RETURNS INT
BEGIN
DECLARE isAvailable INT default 0;

SET isAvailable = IFNULL(SELECT * FROM centre_courses where available_seats > 0, 1, 0);

RETURN is Available;

END;

$$ DELIMITER ;