#include <pqxx/pqxx>
#include <string>
#include <memory>
class DB {
private:
  std::string dbName;
  std::string host;
  std::string port;
  std::string password; 
  std::string username;
  std::unique_ptr<pqxx::connection> conn;

public:
  DB();
  ~DB();
  
  // Executes a query without returning results
  void query(const std::string& sql);
  
  // Executes a query and returns the results
  pqxx::result exec(const std::string& sql);

  // Connection management
  bool isConnected() const;
  void connect();
  void disconnect();

  // Getters/setters for connection params
  void setDbName(const std::string& name) { dbName = name; }
  void setHost(const std::string& h) { host = h; }
  void setPort(const std::string& p) { port = p; }
  void setUsername(const std::string& user) { username = user; }
  void setPassword(const std::string& pass) { password = pass; }
};
