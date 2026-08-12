# Write your MySQL query statement below
SELECT A.machine_id, ROUND(AVG(Ac.timestamp - A.timestamp),3) AS processing_time
FROM Activity AS A 
JOIN Activity AS Ac ON A.machine_id = Ac.machine_id
-- apparently we can also add AND condition here too
-- AND A.process_id = Ac.process_id 
WHERE A.activity_type = "start" AND Ac.activity_type ="end"
GROUP BY A.machine_id
