# Write your MySQL query statement below

Select e.name from Employee e
where 
(select count(e.id) from Employee where e.id=managerID) >= 5