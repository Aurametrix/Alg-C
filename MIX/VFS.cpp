
class VFS {
    ...
public:
    void register_device(Badge<Device>, Device&);
    void unregister_device(Badge<Device>, Device&);
};
