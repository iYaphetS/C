
//通信函数的声明

int socket_init(void **handle);

int send_data(void *handle, char *buf, int len);

int recv_data(void *handle, char *buf, int *len);

int socket_destory(void **handle);