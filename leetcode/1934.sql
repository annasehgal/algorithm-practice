# Write your MySQL query statement below
SELECT S.user_id, ROUND(IFNULL(sum(C.action = 'confirmed') / COUNT(C.action),0), 2) AS confirmation_rate
FROM Signups AS S
LEFT JOIN Confirmations AS C ON C.user_id = S.user_id 
GROUP BY S.user_id
ORDER BY S.user_id DESC
