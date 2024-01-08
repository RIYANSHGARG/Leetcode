Select q.query_name , 
round(avg(q.rating/q.position),2) as quality , 
IFNULL(round(round((select count(rating) from Queries where rating<3 and query_name=q.query_name group by query_name)/count(q.rating),4)*100,2),0) as poor_query_percentage
from Queries q
WHERE query_name is not null
group by q.query_name