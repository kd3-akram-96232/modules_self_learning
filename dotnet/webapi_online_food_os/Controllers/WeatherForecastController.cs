using Microsoft.AspNetCore.Mvc;

namespace webapi_online_food_os.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class WeatherForecastController : ControllerBase
    {

        [HttpGet]
        public IActionResult Get()
        {
            return Ok("Hello from get");
        }

        [HttpGet("Info/v1")]
        public IActionResult Info()
        {
            return Ok("Info");

        }

    }
}