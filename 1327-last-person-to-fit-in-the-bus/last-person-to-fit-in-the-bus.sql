# Write your MySQL query statement below

SELECT person_name
FROM  
(
SELECT person_name, SUM(weight) OVER (ORDER BY turn) as cumulative
From Queue
-- ORDER BY turn 
) as T
where T.cumulative <= 1000
ORDER BY T.cumulative DESC
LIMIT 1;
