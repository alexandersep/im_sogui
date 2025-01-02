const std = @import("std");

pub fn build(b: *std.Build) !void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const exe = b.addExecutable(.{
        .name = "im_sogui",
        .target = target,
        .optimize = optimize,
    });

    exe.linkSystemLibrary("GL");

    exe.addLibraryPath(b.path("lib"));
    exe.addIncludePath(b.path("include"));

    exe.addObjectFile(b.path("lib/raylib/libraylib.a"));

    exe.addCSourceFiles(.{ .files = &generic_source_files });
    exe.linkLibC();

    b.installArtifact(exe);

    const run_cmd = b.addRunArtifact(exe);
    run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);
}

const generic_source_files = [_][]const u8{
    "src/main.c",
    "src/imsogui.c",
};
