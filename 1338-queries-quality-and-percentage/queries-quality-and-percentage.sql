# Write your MySQL query statement below
SELECT q.query_name , 
    ROUND(AVG(q.rating/q.position),2) as quality,
    ROUND(AVG(IF(rating < 3,1,0))*100, 2) AS poor_query_percentage
FROM Queries q
GROUP BY q.query_name;

