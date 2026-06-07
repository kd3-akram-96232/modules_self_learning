using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Microsoft.OpenApi;
using System.Runtime.InteropServices;
using System.Security.Claims;
using webapi_online_food_os.Dto;
using webapi_online_food_os.Model;

namespace webapi_online_food_os.Controllers
{
    //[Authorize]
    [Route("api/[controller]")]
    [ApiController]
    public class FoodController(AppDbContext context) : ControllerBase
    {

        [HttpGet]
        //[Authorize]
        public async Task<IActionResult> Get()
        {
            //foreach (var claim in User.Claims)
            //{
                //Console.WriteLine($"{claim.Type} = {claim.Value}");
            //}
            //Console.WriteLine(User.Identity?.IsAuthenticated);
            //Console.WriteLine("Token Id: " + User.FindFirst("Uid")?.Value);
            //Console.WriteLine("Token Email: " + User.FindFirst("Email")?.Value);

            var foods = await context.Foods.Select(f => new {
                fid = f.Fid,
                name = f.Name,
                price = f.Price,
                description = f.Description,
                image = f.Image
            }).ToListAsync();

            return Ok(ApiResult.Success(foods));
        }

        [Authorize]
        [HttpPost]
        public async Task<IActionResult> Post([FromForm] FoodCreateDto data)
        {
            Console.WriteLine(data.Image);

            string fileName = Guid.NewGuid().ToString() + Path.GetExtension( data?.Image?.FileName );

            string folderPath = Path.Combine(
                    Directory.GetCurrentDirectory(),
                    "wwwroot/FoodImages"
            );

            if (!Directory.Exists(folderPath))
            {
                Directory.CreateDirectory(folderPath);
            }

            string filePath = Path.Combine(folderPath, fileName);

            using(var stream = new FileStream(filePath, FileMode.Create))
            {
                await data?.Image?.CopyToAsync(stream);
            }

            Food food = new Food {
                Name = data.Name,
                Description = data.Description,
                Image = fileName,
                Price = data.Price,
            };

            await context.Foods.AddAsync(food);
            await context.SaveChangesAsync();

            return Ok(ApiResult.Success(food));
        }



        [Authorize]
        [HttpDelete("{id}")]
        public async Task<IActionResult> Delete(int? id)
        {
            int uid = int.Parse(User.FindFirst("Uid")?.Value);

            var food = context.Foods.Find(id);

            if (food == null)
            {
                return Ok(ApiResult.Success("Food not available"));
            }

            context.Foods.Remove(food);
            await context.SaveChangesAsync();

            return Ok(ApiResult.Success("successfully removed"));

        }


    }
}
