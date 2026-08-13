# Write your MySQL query statement below
-- COUNT highest user id and return lexi smallest name
(SELECT name as results
FROM MovieRating 
JOIN Users USING(user_id)
GROUP BY user_id
ORDER BY COUNT(rating)  DESC, name
LIMIT 1
)
UNION ALL

(SELECT title as results
FROM Movies 
JOIN MovieRating USING(movie_id)
WHERE date_format(created_at,"%m-%Y")  = '02-2020'
GROUP BY title
ORDER BY AVG(rating) DESC, title
LIMIT 1)