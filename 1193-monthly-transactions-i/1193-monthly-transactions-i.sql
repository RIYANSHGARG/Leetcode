# Write your MySQL query statement below

Select 
SUBSTR(t.trans_date,1,7) as month , 
t.country , 
count(SUBSTR(t.trans_date,1,7)) as trans_count,
sum(case when state='approved' then 1 else 0 end) as approved_count , 
sum(t.amount) as trans_total_amount, 
sum(case when state='approved' then t.amount else 0 end) as approved_total_amount
from Transactions t
group by month,t.country