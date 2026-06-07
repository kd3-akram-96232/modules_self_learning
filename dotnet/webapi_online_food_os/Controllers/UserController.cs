using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Data.SqlClient;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Internal;
using Microsoft.Identity.Client;
using System.Security.Claims;
using webapi_online_food_os.Dto;
using webapi_online_food_os.Model;
using webapi_online_food_os.Utils;

namespace webapi_online_food_os.Controllers
{

    [Route("api/[Controller]")]
    [ApiController]
    public class UserController(AppDbContext context) : ControllerBase
    {

        public async Task<IActionResult> Get()
        {
            return Ok(ApiResult.Success(await context.Users.ToListAsync()));
        }

        [HttpPost("Signup")]
        public async Task<IActionResult> Signup([FromBody] SignupDto data)
        {

            var existingUser = await context.Users.Where(u => u.Email == data.Email).FirstOrDefaultAsync();

            if (existingUser != null) {
                return BadRequest(ApiResult.Error("User already exist."));
            }

            User newUser = new User {
                Name = data.Name,
                Email = data.Email,
                Mobile = data.Mobile,
                Password = AuthHelper.HashPassword(data.Password),
            };

            await context.Users.AddAsync(newUser);
            await context.SaveChangesAsync();

            return Ok(ApiResult.Success(newUser));
        }


        [HttpPost("Login")]
        public async Task<IActionResult> Login([FromBody] SigninDto data)
        {
            Console.WriteLine("Email: " + data.Email);
            Console.WriteLine("Password: " + data.Password);

            var existingUser = await context.Users.Where(u => u.Email.Equals(data.Email))
                .FirstOrDefaultAsync();

            Console.WriteLine("existingUser: " + existingUser?.Email);

            if(existingUser == null)
            {
                return NotFound(ApiResult.Error("Please do first registration."));
            }

            var isVerified = AuthHelper.VerifyPassword(data.Password, existingUser.Password!);

            if (!isVerified)
            {
                return NotFound(ApiResult.Error("Email or Password is invalid"));
            }

            Claim[] claims = new [] {

                new Claim("Uid", existingUser.Uid.ToString()),
                new Claim("Email", existingUser.Email.ToString())

            };

            var token = AuthHelper.generateJwtToken(claims);


            var cookieOption = new CookieOptions
            {
                HttpOnly = true,
                Secure = false,
                SameSite = SameSiteMode.Lax,
                Expires = DateTime.UtcNow.AddHours(2),
            };

            Response.Cookies.Append("auth_token", token, cookieOption);

            return Ok(ApiResult.Success( new { token } ));

        }

        // Me (Loggedin user)
        [Authorize]
        [HttpGet("me")]
        public async Task<IActionResult> Me()
        {
            var UserId = int.Parse(User.FindFirst("Uid")?.Value);

            var existingUser = await context.Users.Where(u => u.Uid.Equals(UserId)).FirstOrDefaultAsync();

            if(existingUser == null)
            {
                //Response.Cookies.Delete("auth_token");
                return NotFound(ApiResult.Error("User not found"));
            }

            return Ok(ApiResult.Success(existingUser));

        }

        // Me (Loggedin user)
        [Authorize]
        [HttpGet("logout")]
        public async Task<IActionResult> Logout()
        {


            //var UserId = int.Parse(User.FindFirst("Uid")?.Value);

            //var existingUser = await context.Users.Where(u => u.Uid.Equals(UserId)).FirstOrDefaultAsync();

            //if (existingUser == null)
            //{
            //Response.Cookies.Delete("auth_token");
            //return NotFound(ApiResult.Error("User not found"));
            //}

            Response.Cookies.Delete("auth_token");

            return Ok(ApiResult.Success("Logout successfully"));

        }

    }
}