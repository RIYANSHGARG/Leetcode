# Write your MySQL query statement below
# Select name from Customer where referee_id <> 2 or referee_id is NULL;

Select name from Customer where id not in (Select id where referee_id=2);