using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.EntityFrameworkCore.Metadata.Builders;
using Microsoft.Identity.Client;
using Microsoft.IdentityModel.Tokens;
using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using System.Text;
using webapi_online_food_os.Dto;

namespace webapi_online_food_os.Utils
{
    public class AuthHelper ()
    {
        public  static string Issuer { get; set; }
        public  static string Audience { get; set; }
        public  static string JwtKey { get; set; }
        public static WebApplicationBuilder Builder { get; set; }

        public static int ExpiresInMinutes { get; set; } = 20;

        public static void SetBuilder(WebApplicationBuilder builder)
        {
            Builder = builder;
        }

        public static void SetupJwtAuthentication()
        {

            //Audience = Builder.Configuration["Jwt:Audience"]!;
            //Issuer = Builder.Configuration["Jwt:Issuer"]!;
            //JwtKey = Builder.Configuration["Jwt:Key"]!;

            if (Builder == null)
            {
                Console.WriteLine("Please provide builder first");
                return;
            }

            if (string.IsNullOrEmpty(Issuer) || string.IsNullOrEmpty(Audience) || string.IsNullOrEmpty(JwtKey)) {
                Console.WriteLine("Provide Issuer, Audience and JwtKey");
                return;
            }

            Builder.Services.AddAuthentication(JwtBearerDefaults.AuthenticationScheme)
                .AddJwtBearer(options =>
                {
                    options.TokenValidationParameters = new TokenValidationParameters
                    {
                        ValidateIssuer = true,
                        ValidateAudience = true,
                        ValidateLifetime = true,
                        ValidateIssuerSigningKey = true,
                        ValidIssuer = Issuer,
                        ValidAudience = Audience,
                        IssuerSigningKey = new SymmetricSecurityKey(
                            Encoding.UTF8.GetBytes(JwtKey!)
                        )
                    };

                    options.Events = new JwtBearerEvents
                    {

                        OnMessageReceived = context =>
                        {

                            context.Token = context.Request.Cookies["auth_token"];

                            return Task.CompletedTask;

                        },

                        OnChallenge = async context =>
                        {
                            context.HandleResponse();

                            context.Response.StatusCode = 401;
                            context.Response.ContentType = "application/json";

                            await context.Response.WriteAsJsonAsync(ApiResult.Error("Unauthorised"));
                        },

                    };


                });
        }

        public static string generateJwtToken(Claim[] claims)
        {
            Console.WriteLine("Audience: " + Audience);
            Console.WriteLine("Issuer: " + Issuer);
            Console.WriteLine("JwtKey: " + JwtKey);

            var key = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(JwtKey!));

            var creds = new SigningCredentials(key, SecurityAlgorithms.HmacSha256);

            var token = new JwtSecurityToken(
                issuer: Issuer,
                audience: Audience,
                claims: claims,
                expires: DateTime.UtcNow.AddMinutes(ExpiresInMinutes),
                signingCredentials: creds
            );

            return new JwtSecurityTokenHandler().WriteToken(token); 
        }

        public static string HashPassword(string password)
        {
            return BCrypt.Net.BCrypt.HashPassword(password);
        }

        public static bool VerifyPassword(string password, string hashedPassword)
        {
            return BCrypt.Net.BCrypt.Verify(password, hashedPassword);
        }

        //public JwtHelper(string issuer, string audience, string jwtkey)
        //{
        //    Issuer = issuer;
        //    Audience = audience;
        //    JwtKey = jwtkey;
        //}

       

    }
}
