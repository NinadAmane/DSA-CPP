# Write your MySQL query statement below
SELECT
    ROUND(
        COUNT(*) /
        (SELECT COUNT(DISTINCT player_id) FROM Activity),
        2
    ) AS fraction
FROM activity a1
JOIN activity a2 ON a2.player_id = a1.player_id AND (DATEDIFF(a2.event_date, a1.event_date) =1)
WHERE (a1.player_id, a1.event_date) IN
    (SELECT a3.player_id, MIN(event_date)
    FROM activity a3
    GROUP BY a3.player_id)