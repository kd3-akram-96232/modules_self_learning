using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using webapi_online_food_os.Dto;
using webapi_online_food_os.Model;

namespace webapi_online_food_os.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class OrdersController(AppDbContext context) : Controller
    {
        [Authorize]
        [HttpGet]
        //[HttpGet("{uid}")]
        public async Task<IActionResult> Get()
        {
            int uid = int.Parse(User.FindFirst("Uid")?.Value);

            //var orders = await context.Orders.Where(o => o.Uid.Equals(uid)).ToListAsync();

            var orders = await context.Orders.Select(o => new { 
                Uid = o.Uid,
                Oid = o.Oid,
                Odate = o.Odate,
                Deldate = o.Deldate,
                TotalAmount = o.TotalAmount,

                OrderDetails = o.OrderDetails.Select(od => new { 
                    Quantity = od.Quantity,
                    Food = context.Foods.Where(f => f.Fid.Equals(od.Fid)).FirstOrDefault()
                
                }).ToList()

            
            }).Where(o => o.Uid.Equals(uid)).OrderByDescending(o => o.Odate).ToListAsync();

            return Ok(ApiResult.Success(orders));

        }

        [Authorize]
        [HttpPost]
        public async Task<IActionResult> Post ([FromBody] PlaceOrderDto data)
        {
            int UserId = int.Parse(User.FindFirst("Uid")?.Value);

            Order newOrder = new Order
            {
                Uid = UserId,
                TotalAmount = data.TotalAmount,
            };


            await context.Orders.AddAsync(newOrder);
            await context.SaveChangesAsync();

            foreach (var item in data.CartItems)
            {

                OrderDetail newOrderDetails = new OrderDetail
                {
                    Oid = newOrder.Oid,
                    Fid = item.Fid,
                    Quantity = item.Qty
                };
                await context.OrderDetails.AddAsync(newOrderDetails);
            }

            await context.SaveChangesAsync();



            return Ok(ApiResult.Success(new { Uid = newOrder.Uid, Oid = newOrder.Oid, TotalAmount = newOrder.TotalAmount, CartItems = data.CartItems }));
            
        }
    }
}
