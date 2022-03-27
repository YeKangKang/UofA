SELECT Students.given_name, Students.family_name, Enrolments.mark FROM Students INNER JOIN Enrolments
ON Students.student_id = Enrolments.student_id
WHERE Enrolments.subject_code = 'COMP SCI 2000' AND Enrolments.mark < 50;