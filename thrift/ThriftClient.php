<?php
 
error_reporting(E_ALL);
 
require_once __DIR__.'/lib/Thrift/ClassLoader/ThriftClassLoader.php';
 
use Thrift\ClassLoader\ThriftClassLoader;
 
$GEN_DIR = realpath(dirname(__FILE__)).'/gen-php';
 
$loader = new ThriftClassLoader();
$loader->registerNamespace('Thrift', __DIR__ . '/lib');
$loader->register();
 
use Thrift\Protocol\TBinaryProtocol;
use Thrift\Transport\TSocket;
use Thrift\Transport\THttpClient;
use Thrift\Transport\TBufferedTransport;
use Thrift\Exception\TException;
 
class ThriftClient {
 
    public $client;
    private $transport;
    private $protocol;
    private $client_class;
    private $server_ip;
    private $server_port;
    private $socket;
 
    function __construct($client_class, $server_ip='localhost', $server_port=9090){
        $this->client_class = $client_class;
        $this->server_ip = $server_ip;
        $this->server_port = $server_port;
    }
 
    function __destruct(){
        $this->transport->close();
    }
 
    public function getClient(){
        $this->socket = new TSocket($this->server_ip, $this->server_port);
        $this->transport = new TBufferedTransport($this->socket, 1024, 1024);
        $this->protocol = new TBinaryProtocol($this->transport);
        $this->client = new \mongotest\MongoTestClient($this->protocol);
        $this->transport->open();
        return $this->client;
    }
}

?>