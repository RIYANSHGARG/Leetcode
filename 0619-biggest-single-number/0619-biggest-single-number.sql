# Write your MySQL query statement below
Select if(count(num)=1 ,num,null) as num from MyNumbers group by num order by COUNT(num),num DESC limit 1;