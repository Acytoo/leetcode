SELECT class FROM courses
GROUP BY class
HAVING COUNT(DISTINCt student) >= 5;
