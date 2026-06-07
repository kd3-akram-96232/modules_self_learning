using System.Reflection.Metadata.Ecma335;

namespace webapi_online_food_os.Dto
{
    public class ApiResultDto
    {
        public bool Status { get; set; }
        public object Data { get; set; }
        public string Error { get; set; }
    }

    public static class ApiResult
    {
        public static ApiResultDto Success(object data)
        {
            return new ApiResultDto
            {
                Status = true,
                Data = data,
                Error = null
            };
        }

        public static ApiResultDto Error(string data)
        {
            return new ApiResultDto
            {
                Status = false,
                Data = string.Empty,
                Error = data
            };
        }


    }
}
