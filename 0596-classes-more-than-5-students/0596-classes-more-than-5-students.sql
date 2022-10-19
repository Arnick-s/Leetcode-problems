# Write your MySQL query statement below

WITH cte AS
(SELECT class, COUNT(student) AS numStu
FROM Courses 
GROUP BY class)

SELECT cte.class
FROM cte 
WHERE cte.numStu >= 5

