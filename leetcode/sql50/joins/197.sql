# Write your MySQL query statement below
SELECT We.id AS Id
FROM Weather AS W
JOIN Weather AS We ON We.recordDate = DATE_ADD(W.recordDate, INTERVAL 1 DAY)
-- JOIN Weather AS We ON We.recordDate = W.recordDate + 1
-- i learned a new thing on how to solve it lol, DATE_ADD and sub using interval
WHERE We.temperature > W.temperature
