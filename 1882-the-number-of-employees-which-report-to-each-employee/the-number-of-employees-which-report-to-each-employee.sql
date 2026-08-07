# Write your MySQL query statement below
SELECT e.employee_id, e.name, T.reports_count, T.average_age
FROM Employees e JOIN 

-- WHERE (reports_count, average_age) IN
(SELECT reports_to, COUNT(reports_to) as reports_count, ROUND(AVG(age),0) as average_age
FROM Employees 
GROUP BY reports_to
HAVING COUNT(reports_to) > 0)  as T ON e.employee_id = T.reports_to

ORDER BY employee_id