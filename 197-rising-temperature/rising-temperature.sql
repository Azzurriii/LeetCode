/* Write your T-SQL query statement below */

select distinct w2.id
from weather w1
inner join weather w2
    on datediff(day, w1.recordDate, w2.recordDate) = 1
 where w1.temperature < w2.temperature