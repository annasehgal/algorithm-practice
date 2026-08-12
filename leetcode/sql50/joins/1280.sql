# Write your MySQL query statement below
SELECT Stu.student_id, Stu.student_name, Sub.subject_name, COUNT(E.student_id) as attended_exams
FROM  Students AS Stu
CROSS JOIN Subjects AS Sub
LEFT JOIN Examinations AS E ON Stu.student_id = E.student_id AND Sub.subject_name = E.subject_name
GROUP BY Stu.student_id, Stu.student_name, Sub.subject_name
ORDER BY Stu.student_id, Sub.subject_name
