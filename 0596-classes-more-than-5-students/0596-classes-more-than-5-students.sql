# Write your MySQL query statement below
# Select c.class from Courses c where (Select count(c.class) from Courses) > 5 group by class;

select class
from courses 
group by class
having count(distinct student) >= 5