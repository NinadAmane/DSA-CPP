# Write your MySQL query statement below
-- SELECT visited_on, 
--        amount,
--        ROUND(amount/7, 2) as average_amount
-- FROM(
--     SELECT  visited_on, 
--             SUM(amount) OVER(order by visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) as amount
--     FROM (
--         SELECT visited_on, SUM(amount) as amount
--         FROM Customer
--         GROUP BY visited_on
--     ) as daily
-- ) as T

        
-- WHERE visited_on >= (
--     SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY)
--     FROM Customer
-- )

-- ORDER BY visited_on


-- APPROACH 2:
SELECT visited_on,
        (
            SELECT SUM(amount)
            FROM customer
            WHERE visited_on BETWEEN DATE_SUB(c.visited_on, INTERVAL 6 DAY) AND c.visited_on
        ) as amount,

        ROUND(
            (SELECT SUM(amount)/7
            FROM customer
            WHERE visited_on BETWEEN DATE_SUB(c.visited_on, INTERVAL 6 DAY) AND c.visited_on) , 2
        ) as average_amount


FROM Customer c
WHERE visited_on >= (
    SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY)
    FROM Customer
)
GROUP BY visited_on
ORDER BY visited_on