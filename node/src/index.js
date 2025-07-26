const http = require("http");

const server = http.createServer(async (req, res) => {
  if (req.method === "GET" && req.url === "/") {
    console.log("Hi From server");
    res.end();
  }
});

server.listen(3001, () => console.log("Server is listening on port 3001"));
