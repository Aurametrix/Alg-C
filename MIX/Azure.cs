using System.Net;
public static async Task<HttpResponseMessage> Run(HttpRequestMessage req, TraceWriter log)
{
    log.Info("C# HTTP trigger function processed a request.");
    var response = req.CreateResponse();
    response.StatusCode = HttpStatusCode.OK;
    response.Content = new StringContent("<html><head><title>Blog</title></head><body>Hello world</body></html>", System.Text.Encoding.UTF8, "text/html");
    return response;
}
