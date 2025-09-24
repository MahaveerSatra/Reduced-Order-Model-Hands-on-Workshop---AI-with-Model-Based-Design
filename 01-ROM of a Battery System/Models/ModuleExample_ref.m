%%
import simscape.battery.builder.*

Np = 4;
Ns = 10;

batteryCell = Cell();
cellGeometry = PouchGeometry();
cellGeometry.Length = simscape.Value(0.36, "m");
cellGeometry.Height = simscape.Value(0.13, "m");
cellGeometry.TabWidth = simscape.Value(0.05, "m");
cellGeometry.TabLocation = "Opposed";
batteryCell.Geometry = cellGeometry;

batteryCell.Mass = simscape.Value(0.8,"kg");
batteryCell.CellModelOptions.BlockParameters.prm_dyn="rc1";
parallelAssembly = ParallelAssembly(...
    NumParallelCells = Np, ...
    Cell = batteryCell, ...
    Topology = "SingleStack", ...
    InterCellGap = simscape.Value(0.001, "m"));
module = Module(...
    ParallelAssembly = parallelAssembly, ...
    NumSeriesAssemblies = Ns, ... 
    InterParallelAssemblyGap = simscape.Value(0.015, "m"));

% module.ModelResolution='Grouped';
% module.SeriesGrouping=[4 5 5];
module.ModelResolution='Lumped';
f = uifigure("Color", "white");
moduleChart = BatteryChart(Parent = f, Battery = module);
title(moduleChart, "Module Chart")


%%
module.ParallelAssembly.Cell.CellModelOptions.BlockParameters.thermal_port='model';
module.ParallelAssembly.Cell.CellModelOptions.BlockParameters.T_dependence="yes";
module.CoolantThermalPath="CellBasedThermalResistance";
module.CoolingPlate='Bottom';

%%
buildBattery(module,"LibraryName","moduleExample");
