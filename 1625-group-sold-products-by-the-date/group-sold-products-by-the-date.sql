# Write your MySQL query statement below
SELECT sell_date, COUNT(DISTINCT product) as num_sold, GROUP_CONCAT(DISTINCT product order by product) as products
FROM Activities
GROUP BY sell_date
