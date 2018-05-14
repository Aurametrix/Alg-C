struct DeviceSetup {
    enum class TableType : std::uint32_t {
        inphase = 0,
        quadrature,
        table
    };

    std::uint32_t input_source : 8;
    TableType table_type : 4;
    std::uint32_t reserved : 20;
};
