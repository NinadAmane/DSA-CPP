# Write your MySQL query statement below
SELECT visited_on, 
       amount,
       ROUND(amount/7, 2) as average_amount
FROM(
    SELECT visited_on, 
    SUM(amount) OVER(order by visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) as amount
    FROM (
        SELECT visited_on, SUM(amount) as amount
        FROM Customer
        GROUP BY visited_on
    ) as daily
) as T

        
WHERE visited_on >= (
    SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY)
    FROM Customer
)

ORDER BY visited_on