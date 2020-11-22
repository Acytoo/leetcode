# Write your MySQL query statement below
SELECT Email
FROM Person
GROUP BY Email
HAVING COUNT(Email) > 1;

# Solution2:
SELECT DISTINCT p1.Email 
FROM Person p1, Person p2
WHERE p1.Email = p2.Email
AND p1.Id != p2.Id;