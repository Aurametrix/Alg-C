using Aspose.Imaging;
using Aspose.Imaging.FileFormats.Png;
using Aspose.Imaging.ImageOptions;
using System.Collections.Generic;
using System.IO;
using System.Linq;

//Folder that contains set of test template files for all formats
string templatesFolder = @"c:\Users\USER\Downloads";
ProcessConvertion();

void ProcessConvertion()
{        
    //Get list of supported formats in
    //Aspose.Imaging for loading and saving images
    var formats = GetAvailableImageFormats();
    var importFormats = formats.Import;
    var exportFormats = formats.Export;

    //Process each raster and vector format that can be loaded
    foreach (var format in importFormats)
    {
        string formatExt = format.Key;
        var inputFile = Path.Combine(templatesFolder, $"template.{formatExt}");

        //Process each raster and vector format
        //to which we can save imported image
        foreach (var exportFormat in exportFormats)
        {
            var outputFile = Path.Combine(templatesFolder, "convert", $"convert-{formatExt}-to-{exportFormat.Key}.{exportFormat.Key}");
            System.Console.WriteLine("Processing conversion:" + outputFile);
            //More about load method can be found at
            //https://apireference.aspose.com/imaging/net/aspose.imaging.image/load/methods/2
            //Load imported image
            using (var image = Image.Load(inputFile))
            {
                //Obtain default saving options defined for each image
                ImageOptionsBase exportOptions = exportFormat.Value.Clone();
                
                //If loaded image is vector, need to specify vector rasterization options 
                //for export to another vector
                if (image is VectorImage)
                {
                    VectorRasterizationOptions rasterizationOptions = format.Value;
                    rasterizationOptions.PageWidth = image.Width;
                    rasterizationOptions.PageHeight = image.Height;
                    exportOptions.VectorRasterizationOptions = rasterizationOptions;
                }

                image.Save(outputFile, exportOptions);
            }
        }
    }
}

(Dictionary<string, VectorRasterizationOptions> Import, Dictionary<string, ImageOptionsBase> Export) GetAvailableImageFormats()
{
    ////////////////////////////////
    ///Raster and vector formats to that we can export images
    ////////////////////////////////


    //Raster image formats that support both - save and load and their default save options
    Dictionary<string, ImageOptionsBase> rasterFormatsThatSupportExportAndImport = new Dictionary<string, ImageOptionsBase>()
            {
                { "bmp", new BmpOptions()},
                { "gif", new GifOptions()},
                { "dicom", new DicomOptions()},
                { "jpg", new JpegOptions()},
                { "jpeg", new JpegOptions()},
                { "jpeg2000", new Jpeg2000Options() },
                { "j2k", new Jpeg2000Options { Codec = Aspose.Imaging.FileFormats.Jpeg2000.Jpeg2000Codec.J2K } },
                { "jp2", new Jpeg2000Options { Codec = Aspose.Imaging.FileFormats.Jpeg2000.Jpeg2000Codec.Jp2 }},
                { "png",new PngOptions(){ ColorType = PngColorType.TruecolorWithAlpha} },
                { "apng", new ApngOptions()},
                { "tiff", new Aspose.Imaging.ImageOptions.TiffOptions(Aspose.Imaging.FileFormats.Tiff.Enums.TiffExpectedFormat.Default)},
                { "tif", new Aspose.Imaging.ImageOptions.TiffOptions(Aspose.Imaging.FileFormats.Tiff.Enums.TiffExpectedFormat.Default)},
                { "tga", new TgaOptions()},
                { "webp", new WebPOptions()}
            };

    //Vector image formats that support both - save and load, their default save options
    //and their rasterization options when exporting to another vector image
    Dictionary<string, (ImageOptionsBase, VectorRasterizationOptions)> vectorFormatsThatSupportExportAndImport
        = new Dictionary<string, (ImageOptionsBase, VectorRasterizationOptions)>()
    {
                { "emf", (new EmfOptions(),new EmfRasterizationOptions()) },
                { "svg", (new SvgOptions(), new SvgRasterizationOptions())},
                { "wmf", (new WmfOptions(), new WmfRasterizationOptions())},
                { "emz", (new Aspose.Imaging.ImageOptions.EmfOptions(){ Compress = true }, new EmfRasterizationOptions())},
                { "wmz", (new Aspose.Imaging.ImageOptions.WmfOptions(){ Compress = true }, new WmfRasterizationOptions())},
                { "svgz", (new Aspose.Imaging.ImageOptions.SvgOptions(){ Compress = true }, new SvgRasterizationOptions())},
    };



    ////////////////////////////////
    ///Raster and vector formats from which we can load images
    ////////////////////////////////



    //Formats that can be only saved (supported only save to this formats)
    Dictionary<string, ImageOptionsBase> formatsOnlyForExport = new Dictionary<string, ImageOptionsBase>()
            {
                { "psd", new PsdOptions()},
                { "dxf", new DxfOptions(){ TextAsLines = true,ConvertTextBeziers = true} },
                { "pdf", new PdfOptions()},
                { "html", new Html5CanvasOptions()},
            };

    //Raster formats that can be only loaded            
    List<string> formatsOnlyForImport = new List<string>()
            {
                "djvu", "dng", "dib"
            };

    //Vector formats only for loading and their rasterization options when exporting to another vector format
    Dictionary<string, VectorRasterizationOptions> vectorFormatsOnlyForImport = new Dictionary<string, VectorRasterizationOptions>()
            {
                {"eps", new EpsRasterizationOptions()},
                {"cdr", new CdrRasterizationOptions() },
                {"cmx", new CmxRasterizationOptions() },
                {"otg", new OtgRasterizationOptions() },
                {"odg", new OdgRasterizationOptions() }
            };

    //Get total set of formats to what we can export images
    Dictionary<string, ImageOptionsBase> exportFormats = vectorFormatsThatSupportExportAndImport
        .ToDictionary(s => s.Key, s => s.Value.Item1)
        .Union(formatsOnlyForExport)
        .Concat(rasterFormatsThatSupportExportAndImport)
        .ToDictionary(s => s.Key, s => s.Value);

    //Get total set of formats that can be loaded
    Dictionary<string, VectorRasterizationOptions> importFormats = vectorFormatsOnlyForImport
        .Union(formatsOnlyForImport.ToDictionary(s => s, s => new VectorRasterizationOptions()))
        .Union(vectorFormatsThatSupportExportAndImport.ToDictionary(s => s.Key, s => s.Value.Item2))
        .ToDictionary(s => s.Key, s => s.Value);

    return (Import: importFormats, Export: exportFormats);
}
