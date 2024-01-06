# Write your MySQL query statement below

Select s.student_id,s.student_name,b.subject_name,count(e.subject_name) AS attended_exams
from Students s 
join Subjects b
left join Examinations e
on s.student_id=e.student_id and e.subject_name=b.subject_name
group by s.student_id,s.student_name,b.subject_name
order by s.student_id,b.subject_name