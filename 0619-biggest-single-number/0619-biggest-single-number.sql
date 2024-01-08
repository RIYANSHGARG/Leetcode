# Write your MySQL query statement below
# Select if(count(num)=1 ,num,null) as num from MyNumbers group by num order by COUNT(num),num DESC limit 1;

SELECT MAX(num) AS num FROM (SELECT num FROM MyNumbers GROUP BY num HAVING COUNT(num) = 1 ) NEWTable;
