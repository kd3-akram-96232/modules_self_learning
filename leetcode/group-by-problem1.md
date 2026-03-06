![alt text](./../__metadata/image.png)


```sql

select customer_number from orders group by customer_number having count(order_number) order by count(order_number) desc limit 1;

```

