# Write your MySQL query statement below

Select r.contest_id,round((count(r.user_id)/ (Select count(user_id) from Users))*100,2) as percentage 
from 
Users u join Register r
on u.user_id=r.user_id
group by r.contest_id
order by percentage DESC, contest_id 